/*
 * Say you use SVN for source control..you have several revisions of a file...R1, r2, r3..etc..Someone checked in a bug and the revision became bad..need t find the first bad revision..gave a function findBadRevision(int goodRevision, int badRevision) so for e.g the revisions were GGBB and function passes in 0,4 so the first bad revision is 2. There exists a function boolean hasBug(int revision) which will tell us if a certain revision has a bug. can assume good revision < bad revision
 */
public class FindBadRevision {
    static int findBadRevision(String revisions) {
        int l, r, m;
        l = 0; 
        r = revisions.length()-1;
        while(l<r) {
            m = l + (r-l)/2;
            if (revisions.charAt(m) == 'G') l = m+1;
            else r = m;
        }
        if (l == r && revisions.charAt(l) == 'G') 
            System.out.println("no bad revision");
        return l;
    }

    public static void main(String[] args) {
        System.out.println(findBadRevision("GGGG"));
    }

}
