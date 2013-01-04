#include "ImageExample.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include "WebImageView.h"
#include <bb/cascades/Button>
using namespace bb::cascades;

ImageExample::ImageExample(bb::cascades::Application *app)
: QObject(app)
{
    // create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime

	qmlRegisterType<WebImageView>("org.labsquare", 1, 0, "WebImageView");

    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
    // create root object for the UI

    AbstractPane *root = qml->createRootObject<AbstractPane>();
    // set created root object as a scene
    app->setScene(root);
}

