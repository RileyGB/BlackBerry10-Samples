// Default empty project template
import bb.cascades 1.0
import org.labsquare 1.0
// creates one page with a label
Page {
    Container {
        layout: DockLayout {}
          WebImageView {
              id:img
              url:"http://syvolc.briolet.fr/wp-uploads/2010/11/qt-logo1.jpg"
               horizontalAlignment: HorizontalAlignment.Center
               verticalAlignment: VerticalAlignment.Center
               visible: (img.loading == 1.0)
        }
        ProgressIndicator {
            value: img.loading
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            visible: (img.loading < 1.0)
        }
    }
 }
              
                             


