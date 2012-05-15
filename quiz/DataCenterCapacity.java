import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * @author XJ
 * 
 * This class calculates the capacity given input about data center
 * M Groups and N machine in each group
 * K is number of unique versions (worst case K = M*N)
 * 
 * Space Complexity: 
 * 		O(K*N)  (worse case O(M*N*N))
 * Time: 
 * 		O(M*N) + O(K*N) (worse case O(M*N*N))
 * 
 * Idea:
 * 		Capacity for each version is bounded by the minimum number of copies on each subset for that version.
 * 		Total capacity = Sum of capacity for each version
 * 		
 * Data Structure Used:
 * 		HashMap (amortized O(1) read/write) 
 * 			key (Integer): version number
 * 			Value (ArrayList<Integer>: counts for each subset - length N, O(1) read/write for array
 *  
 */
public class DataCenterCapacity {
    private int capacity_per_group; // capacity for each group
	private Map<Integer, ArrayList<Integer>> map; 
	
	public DataCenterCapacity(int request_per_second) {
		capacity_per_group = request_per_second;
		initMap();
	}
	
	private void initMap() {
		map = new HashMap<Integer, ArrayList<Integer>>();
	}

	/* 
	 * Read data from stdin and store data into hashmap
	 */
    private void readData() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Please enter M and N:");
        String s = br.readLine();
        String[] arr = s.split("[\t\\s]+");
        if (arr.length != 2) {
        	throw new IllegalArgumentException("Incorrect M and N");
        }
        int M = Integer.parseInt(arr[0]);
        int N = Integer.parseInt(arr[1]);
        for (int i=0; i<M; i++) {
        	s = br.readLine();
        	arr = s.split("[\t\\s]+");
        	if (arr.length != N) 
        		throw new IllegalArgumentException("Need " + N + " data each line");
        	storeData(arr);
        }
    }
    
    /*
     * Store subset count for each version
     */
    private void storeData(String[] arr) {
    	for (int j=0; j<arr.length; j++) {
    		int val = Integer.parseInt(arr[j]);
    		ArrayList<Integer> list = map.get(val);
    		if (null == list) {
    			Integer[] initial_array = new Integer[arr.length];
    			Arrays.fill(initial_array, 0); // initialize to 0
    			list = new ArrayList<Integer>(Arrays.asList(initial_array));
    		}
    		list.set(j, list.get(j)+1); //increment counter
    		map.put(val,list);
    	}
    }
    
    /*
     * Calculate capacity by iterate through map values
     */
    private int calculateCapacity() {
    	int capacity = 0;
    	for (ArrayList<Integer> list : map.values()) {
    		int min = Integer.MAX_VALUE;
    		for (int count : list) {
    			if (count < min) min = count;
    			// if any subset count is 0, capacity for this version is zero
    			// no need to calculate further
    			if (min == 0) break;  
			}
    		capacity += min * capacity_per_group;
		}
    	return capacity;
    }
    
    /*
     * A simple Unit test 
     */
    private void test() {
    	String[][] sample_data = new String[][] {
    			{"103", "107", "103", "107", "107"},
    			{"107", "103", "107", "107", "103"},
    			{"103", "107", "107", "103", "103"},
    			{"103", "103", "107", "107", "107"}
    	};
    	for (String[] strings : sample_data) {
    		storeData(strings);
		}
    	assert calculateCapacity() == 200;
    	initMap();
    }
    
    public static void main(String[] args) throws IOException {
    	DataCenterCapacity dcc = new DataCenterCapacity(100);
    	dcc.readData();
    	System.out.println("Output");
    	System.out.println(dcc.calculateCapacity());
    }
}
