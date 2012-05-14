/*
 * http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html
 */

public class PointInPolygon {
    // for edge case like on boundary, may need special handling for desired output
    // this code only guarrantee consist result for boundary case, refer to the graph in origin link
    static boolean isPointInPolygon(float x, float y, float[] vertx, float[] verty) {
        if (vertx.length != verty.length) 
            throw new IllegalArgumentException();
        int n = vertx.length;
        boolean r = false;
        for (int i=0, j=n-1; i<n; j=i++) {
            if (
                    ((y>verty[i]) != (y>verty[j])) 
                 && (x < ((vertx[j] == vertx[i])? vertx[i] :
                     vertx[i] + (y-verty[i]) * (verty[j]-verty[i]) / (vertx[j]-vertx[i])))
               ) {
                //System.out.println(i+"-"+j+" "+(vertx[j]-vertx[i]));
                r = !r;
               }
        }
        return r;
    }

    public static void main(String[] args) {
        for (int i=0, j=3; i<4; j=i++) {
            //System.out.println(i+"-"+j);
        }
        float[] vertx = new float[] {0, 2, 2, 0}; 
        float[] verty = new float[] {2, 2, 0, 0}; 
        System.out.println(isPointInPolygon(1.5,1.5f,vertx,verty));
    }
}
