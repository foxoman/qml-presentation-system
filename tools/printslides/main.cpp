/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QML Presentation System.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights. These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Digia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include <QtGui>
#include "slideview.h"

/** PrintSlides main program.
    A program to print qt-labs qml-presentation-system Presentations.
    @author ezust@ics.com
*/
int main (int argc, char* argv[]) {
    QGuiApplication app(argc, argv);
    app.setOrganizationDomain("com");
    app.setOrganizationName("ics");
    app.setApplicationName("printslides");
    app.setApplicationVersion("0.2");
    app.setApplicationDisplayName("QML Presentation Slide Printer");
    SlideView mainView;
    argc = app.arguments().length();
    if ((argc != 2) || app.arguments()[1].endsWith("?")) {
        QString progName = app.applicationName();
        QString message = QString().arg(progName);
        qFatal("%s usage: \n\t    %s path/to/presentation.qml\n"
            "Displays and prints each slides to slides.pdf\n",
            progName.toLocal8Bit().constData(),
            progName.toLocal8Bit().constData());
        return 2;
    }
    mainView.setSource(app.arguments()[1]);
    mainView.show();
    return app.exec();
}
