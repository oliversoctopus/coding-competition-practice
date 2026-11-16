//### Reveal cards in increasing order

import java.io.*;
import java.util.*;
public class cards {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine()); //num of cards

		int[] A = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int j=0; j<N; j++)
			A[j] = Integer.parseInt(st.nextToken());
		
		//simulate the process in reverse order
	    Arrays.sort(A);
	    
	    ArrayDeque<Integer> adq = new ArrayDeque<>();
	    for(int i=N-1; i>=0; i--) {
	    	//move the last element to the front
	    	if(!adq.isEmpty()) 
	    		adq.addFirst(adq.pollLast());

	    	//add A[i] to the front
	    	adq.addFirst(A[i]);
	    }

	    for(int i=0; i<N; i++)
	        System.out.print(adq.pollFirst() + " ");
		System.out.println();
		br.close();
	}
}