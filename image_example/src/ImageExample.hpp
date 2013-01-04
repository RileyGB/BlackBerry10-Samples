// Default empty project template
#ifndef ImageExample_HPP_
#define ImageExample_HPP_

#include <QObject>

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ImageExample : public QObject
{
    Q_OBJECT
public:
    ImageExample(bb::cascades::Application *app);
    virtual ~ImageExample() {}
};


#endif /* ImageExample_HPP_ */
