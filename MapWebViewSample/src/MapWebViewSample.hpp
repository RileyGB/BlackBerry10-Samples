#ifndef MapWebViewSample_HPP_
#define MapWebViewSample_HPP_

#include <QObject>
#include <bb/cascades/Application>

using namespace bb::cascades;

namespace bb {
namespace cascades {
class QmlDocument;
}
}

class MapWebViewSample: public QObject {
Q_OBJECT
public:
	MapWebViewSample(bb::cascades::Application *app);
	virtual ~MapWebViewSample() {
	}

private:

	void initializeLocation();
	void createMapController();

	QmlDocument *mQmlDocument;
};

#endif /* MapWebViewSample_HPP_ */
