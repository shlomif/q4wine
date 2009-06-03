/***************************************************************************
 *   Copyright (C) 2008, 2009 by Malakhov Alexey                           *
 *   brezerk@gmail.com                                                     *
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
 *   In addition, as a special exception, the copyright holders give       *
 *   permission to link the code of this program with any edition of       *
 *   the Qt library by Trolltech AS, Norway (or with modified versions     *
 *   of Qt that use the same license as Qt), and distribute linked         *
 *   combinations including the two.  You must obey the GNU General        *
 *   Public License in all respects for all of the code used other than    *
 *   Qt.  If you modify this file, you may extend this exception to        *
 *   your version of the file, but you are not obligated to do so.  If     *
 *   you do not wish to do so, delete this exception statement from        *
 *   your version.                                                         *
 ***************************************************************************/

#ifndef PREFIX_H
#define PREFIX_H

#include <config.h>

#include <QList>
#include <QString>
#include <QStringList>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariant>


/*!
 * \class Prefix
 * \ingroup database
 * \brief This class provide database functions for prefix table.
 *
 */
class Prefix
{
  public:
	 /*! \brief This is calss constructor.
	  */
	  Prefix();
  
	 /*! \brief This function gets requested table fields from table.
	  *
	  * \param  fields  List of table fields names.
	  * \return Return QList of QStringList with selected value or -1 on error.
	  */
	  QList<QStringList> getFields(const QStringList fields) const;
  
	 /*! \brief This function get requested table fields by keys value from table.
	  *
	  * \param  fields  A table fields names.
	  * \param  keys    A table key fields names.
	  * \param  vals    A table key fields values.
	  * \return Return a list of table fields value or -1 on error.
	  */
	  QList<QStringList> getFieldsByKey(const QStringList fields, const QStringList keys,  const QStringList vals) const;
  
	 /*! \brief This function gets all table fields by key value from table.
	  *
	  * \param  key    A table key field name.
	  * \param  val    A table key field value.
	  * \return Return a list of table fields value or -1 on error.
	  */
	  QList<QStringList> getFieldsByKey(const QString key, const QString val) const;
  
	 /*! \brief This function get all fields from prefix table.
	  *
	  * \return Return a list of table fields value or -1 on error.
	  */
	  QList<QStringList> getFields(void) const;

	 /*! \brief This function gets all table fields by prefixName key value from table.
	  *
	  * \param  prefixName Prefix name key value.
	  * \return Return a list of table fields value or -1 on error.
	  */
	  QStringList getFieldsByPrefixName(const QString prefixName) const;

	 /*! \brief This function executes requested query.
	  *
	  * \param  SQL Query
	  * \return Return true on success
	  */
	  bool updateQuery(QSqlQuery *sqlQuery) const;

  protected:
	 //! This variable defines which table is used by class
	  QString _TABLE;
};

#endif // PREFIX_H
