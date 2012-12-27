// Default empty project template
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include <QLocale>
#include <QTranslator>
#include <Qt/qdeclarativedebug.h>
#include "MapWebViewSample.hpp"
#include "controllers/LocationSession.hpp"

using namespace bb::cascades;

void myMessageOutput(QtMsgType type, const char *msg)
{
	//in this function, you can write the message to any stream!
	switch (type) {
	case QtDebugMsg:
		fprintf(stderr, "Debug: %s\n", msg);
		break;
	case QtWarningMsg:
		fprintf(stderr, "Warning: %s\n", msg);
		break;
	case QtCriticalMsg:
		fprintf(stderr, "Critical: %s\n", msg);
		break;
	case QtFatalMsg:
		fprintf(stderr, "Fatal: %s\n", msg);
		abort();
		break;
	}
}

Q_DECL_EXPORT int main(int argc, char **argv)
{
	// Handle qDebug and console.log
	qInstallMsgHandler(myMessageOutput);

	// Register location so that it can be started via QML
	qmlRegisterType<LocationSession>();

    // this is where the server is started etc
    Application app(argc, argv);

    // localization support
    QTranslator translator;
    QString locale_string = QLocale().name();
    QString filename = QString( "MapWebViewSample_%1" ).arg( locale_string );
    if (translator.load(filename, "app/native/qm")) {
        app.installTranslator( &translator );
    }

    new MapWebViewSample(&app);

    // we complete the transaction started in the app constructor and start the client event loop here
    return Application::exec();
    // when loop is exited the Application deletes the scene which deletes all its children (per qt rules for children)
}
