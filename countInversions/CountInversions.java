import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;


public class CountInversions {

	private static String inputFile = "C:\\Users\\Nikhil\\workspace\\Count Inversions\\src\\inputFile.txt";
	private static ArrayList<Integer> numbers;
	
	
	public static void main(String args[]) throws IOException{
		CountSplitInversions invCounter = new CountSplitInversions();
double count = invCounter.countSplitInversionsFromFile(CountInversions.inputFile);
		
//		int num[] = new int[6];
//		for(int i = num.length-1; i>=0;i--){
//			num[i] = num.length - i;
//		}
//		
//		double count = invCounter.countInversionsReccursion(num, 0, num.length-1);
		
		System.out.println(count);
	}		
	
}
