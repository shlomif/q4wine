/***************************************************************************
 *   Copyright (C) 2008-2016 by Alexey S. Malakhov <brezerk@gmail.com>     *
 *                                                                         *
 *   This program is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 ***************************************************************************/

#include <QtTest/QtTest>

#include "src/lib/defines.hpp"
#include "src/lib/wineapplication.hpp"
#include "src/lib/wineprefix.hpp"
#include "src/lib/wineversion.hpp"

class test_Q4WineLib: public QObject {
    Q_OBJECT
 private slots:
    void testWineVersion();
    void testWinePrefix();
    void testWineApplication();
};

void test_Q4WineLib::testWineVersion() {
    q4wine::lib::WineVersion version = q4wine::lib::WineVersion("binary",
                                  "loader", "server", "libs32", "libs64");
    QCOMPARE(version.getId(), uint32_t(0));
    QCOMPARE(version.getBinary(), QString("binary"));
    QCOMPARE(version.getServer(), QString("server"));
    QCOMPARE(version.getLoader(), QString("loader"));
    QCOMPARE(version.getLibs32(), QString("libs32"));
    QCOMPARE(version.getLibs64(), QString("libs64"));
    QCOMPARE(version.getLibs(q4wine::lib::WIN32), QString("libs32"));
    QCOMPARE(version.getLibs(q4wine::lib::WIN64), QString("libs64"));
}

void test_Q4WineLib::testWinePrefix() {
    q4wine::lib::WinePrefix* prefix = new q4wine::lib::WinePrefix("test",
                "/root", q4wine::lib::WIN32,
                new q4wine::lib::WineVersion("binary",
                "loader", "server", "libs32", "libs64"),
                "/mnt/cdrom", "D:",
                "some_exec_tempalte", 12);

    // Basic unit tests
    QCOMPARE(prefix->getId(), uint32_t(12));
    QCOMPARE(prefix->getName(), QString("test"));
    QCOMPARE(prefix->getPath(), QString("/root"));
    QCOMPARE(prefix->getArch(), q4wine::lib::WIN32);
    QCOMPARE(prefix->getMountPoint(), QString("/mnt/cdrom"));
    QCOMPARE(prefix->getVirtualDevice(), QString("D:"));
    QCOMPARE(prefix->getExecutionTemplate(), QString("some_exec_tempalte"));

    // Advanced unit tests
    QCOMPARE(prefix->getWineEnv(), QString("WINEPREFIX='/root' "
"WINESERVER='server' WINELOADER='loader' WINEDLLPATH='libs32' "
"WINEARCH='win32'"));

    delete(prefix);
}

void test_Q4WineLib::testWineApplication() {
    q4wine::lib::WineApplication application = q4wine::lib::WineApplication(
                "test app",
                "C://test.exe",
                "--make all --quality=good",
                "C://",
                "",
                "Some test app",
                "libgcc.dll=b,n",
                "warn+dll,+heap",
                "600x800",
                "RU_ru",
                true,
                ":1",
                -110,
                "/usr/lib/pre_run.sh",
                "echo done >> /tmp/lol");
    QCOMPARE(application.getName(), QString("test app"));
    QCOMPARE(application.getPath(), QString("C://test.exe"));
    QCOMPARE(application.getArgs(), QString("--make all --quality=good"));
}

QTEST_MAIN(test_Q4WineLib)
#include "test_q4winelib.moc"
