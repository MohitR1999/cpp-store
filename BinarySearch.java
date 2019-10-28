import java.lang.reflect.Array;
import java.util.Arrays;

public class BinarySearch {
	static int binarySearch(int arr[], int x) {
		int low = 0;
		int hight = arr.length-1;
		int result = -1;
		while(low <= hight) {
			int middle = (low+hight)/2;
			if(arr[middle]==x) {
				result = middle;
				break;
			}
			else if(x < arr[middle]) {
				hight = middle-1;
			}
			else if(x > arr[middle]){
				low = middle+1;
			}
		}
		return result;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr[] = {5,4,6,8,9,10,20,3};
		Arrays.sort(arr);
		System.out.println("Array before sort");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+ " ");
		}
		System.out.println();
		int x = 9;
		int result = binarySearch(arr, x);
		if(result==-1) {
			System.out.println("Element not present");
		}
		else {
			System.out.println("Element found at index " + result);
		}
	}

}
