/***************************************************************************
                          docclipbaseiterator.h  -  description
                             -------------------
    begin                : Sat Aug 10 2002
    copyright            : (C) 2002 by Jason Wood
    email                : jasonwood@blueyonder.co.uk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef EFFECTSLIST_H
#define EFFECTSLIST_H

#include <QList>

/**An List for DocClipBase objects. Use this instead of QList<DocClipBase> so as to sort lists correctly.
 * Also contains the ability to set a "master clip", which can be used by a number of operations where
 * the need for one clip to act as a reference for what happens to all clips is needed.
  * @author Jason Wood
  */

#include <QDomElement>

class EffectsList: public QList < QDomElement > {
public:
    EffectsList();
    ~EffectsList();
    /** Returns an XML version of this Effect.*/
    QDomElement getEffectByName(const QString & name) const;
    QDomElement getEffectByTag(const QString & tag, const QString & id) const;
    /** if the list contains effect defined by tag + id, returns effect index, otherwise -1 */
    int hasEffect(const QString & tag, const QString & id) const;
    QStringList effectIdInfo(const int ix) const;
    QStringList effectNames();
    QString getInfo(const QString & tag, const QString & id) const;
    QString getInfoFromIndex(const int ix) const;
    EffectsList clone() const;
    static bool hasKeyFrames(QDomElement effect);
    static void setParameter(QDomElement effect, const QString &name, const QString &value);
    static QString parameter(QDomElement effect, const QString &name);
};

#endif
