// Default empty project template
import bb.cascades 1.0
import org.labsquare 1.0
// creates one page with a label
Page {
    Container {
        layout: DockLayout {
        }
        WebImageView {
            id: webViewImage
            url: "http://syvolc.briolet.fr/wp-uploads/2010/11/qt-logo1.jpg"
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            visible: (webViewImage.loading == 1.0)
        }
        ProgressIndicator {
            value: webViewImage.loading
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            visible: (webViewImage.loading < 1.0)
        }
    }

    actions: [
        ActionItem {
            title: "Clear Cache"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                webViewImage.clearCache();
                webViewImage.url = "http://syvolc.briolet.fr/wp-uploads/2010/11/qt-logo1.jpg";
            }
        }
    ]
}
