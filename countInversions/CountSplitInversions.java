import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;

public class CountSplitInversions {
	private static String inputFile;

	public static String getInputFile() {
		return inputFile;
	}

	public static void setInputFile(String inputFile) {
		CountSplitInversions.inputFile = inputFile;
	}

	private static ArrayList<Integer> numbers;

	public double countSplitInversionsFromFile(String inputFile)
			throws NullPointerException, NumberFormatException, IOException {
		if (inputFile == null) {
			throw new NullPointerException("inputFile parameter is null.");
		}
		CountSplitInversions.inputFile = inputFile;

		numbers = new ArrayList<Integer>();

		BufferedReader br = new BufferedReader(new FileReader(inputFile));
		String inputLine;

		while ((inputLine = br.readLine()) != null) {
			numbers.add(Integer.parseInt(inputLine));
		}

		br.close();
		
		Iterator<Integer> itr = numbers.iterator();
		int num[] = new int[numbers.size()];
		for (int i = 0; i < num.length && itr.hasNext(); i++) {
			num[i] = ((Integer) itr.next()).intValue();
		}

		double splitInversions = countInversionsReccursion(num, 0, num.length - 1);
		return splitInversions;
	}

	public double countInversionsReccursion(int num[], int start, int end) {
		if (end <= start) {
			return 0;
		}
		int mid = (end - start) / 2;
		double count1 = countInversionsReccursion(num, start, start + mid);
		double count2 = countInversionsReccursion(num, start + mid + 1, end);
		double splitCount = mergeAndCountSplitInversions(num, start, start + mid, start + mid + 1, end);

		return (count1 + count2 + splitCount);
	}

	private double mergeAndCountSplitInversions(int num[], int start1, int end1, int start2, int end2) {
		int store[] = new int[end2 - start1 + 1];
		double inversionCount = 0;
		boolean arrayChanged = false;

		int i,j,k;
		for (i = 0, j = start1, k = start2; i < store.length && j <= end1 && k <= end2; i++) {
			if (num[j] < num[k]) {
				store[i] = num[j];
				j++;
			} else if (num[j] > num[k]) {
				store[i] = num[k];
				k++;
				inversionCount += end1 - j + 1;
			}					
		}
		
		while(j<=end1 || k<=end2){
			if(j<=end1){
				store[i++] = num[j++];				
			}else if(k<= end2){
				store[i++] = num[k++];
			}
		}
			
		if (inversionCount > 0) {
			i = start1;
			for (int x : store) {
				num[i++] = x;
			}
		}
		return inversionCount;
	}
}
