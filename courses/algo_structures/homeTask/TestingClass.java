package com.maxdev.hometask;

import java.util.Arrays;

/**
 * <b> Class with main function. </b> <br />
 * Illustrates benchmarking of several experiments: <br />
 * - Quicksort sorting algorithm (experiment1 experiment2). <br />
 * - Deleting from dictionary with different inner build (experiment3). <br />
 * To view result of any experiment, uncomment certain line in main function.
 * 
 * @author MaxGonchar
 *
 */
public class TestingClass {

	final static int maxBound = 1_000_000;

	static void experiment1() {
		DataGenerator generator = new DataGenerator(maxBound);
		long startTime = 0, endTime = 0;
		double estTime = 0.0;

		// Array with random numbers.
		int[] averageTestSet = generator.generateAverageCase(10000);
		QuickSorter sorter = new QuickSorter(averageTestSet);
		// Array with best pivot placement.
		int[] bestTestSet = generator.generateBestCase(10000);
		QuickSorter sorter2 = new QuickSorter(bestTestSet);
		// Array with worst pivot placement.
		int[] worstTestSet = generator.generateWorstCase(10000);
		QuickSorter sorter3 = new QuickSorter(worstTestSet);

		System.out.println("Sorting random set of numbers - average case.");
		startTime = System.nanoTime();
		sorter.quicksort(0, averageTestSet.length - 1);
		endTime = System.nanoTime();
		estTime = (endTime - startTime) / 1000000000.0;
		System.out.println("Estimated time for average case: " + estTime + "\n");

		System.out.println("Sorting sequence with best pivot placement.");
		startTime = System.nanoTime();
		sorter2.quicksort(0, bestTestSet.length - 1);
		endTime = System.nanoTime();
		estTime = (endTime - startTime) / 1000000000.0;
		System.out.println("Estimated time for best case: " + estTime + "\n");

		System.out.println("Sorting sequence with worst pivot placement.");
		startTime = System.nanoTime();
		sorter3.quicksort(0, worstTestSet.length - 1);
		endTime = System.nanoTime();
		estTime = (endTime - startTime) / 1000000000.0;
		System.out.println("Estimated time for worst case: " + estTime + "\n");
	}

	static void experiment2() {
		DataGenerator generator = new DataGenerator(maxBound);
		long startTime = 0, endTime = 0;
		double estTime = 0.0;

		// Array with random numbers.
		int[] averageTestSet = generator.generateAverageCase(10000);
		QuickSorter sorter = new QuickSorter(averageTestSet.clone());
		// Array with best pivot placement.
		int[] bestTestSet = generator.generateBestCase(10000);
		QuickSorter sorter2 = new QuickSorter(bestTestSet.clone());
		// Array with worst pivot placement.
		int[] worstTestSet = generator.generateWorstCase(10000);
		QuickSorter sorter3 = new QuickSorter(worstTestSet.clone());

		
		System.out.println("Sorting random set of numbers - average case.");
		startTime = System.nanoTime();
		sorter.quicksort(0, averageTestSet.length - 1);
		endTime = System.nanoTime();
		estTime = (endTime - startTime) / 1000000000.0;
		System.out.println("Estimated time: " + estTime);
		startTime = System.nanoTime();
		Arrays.sort(averageTestSet);
		endTime = System.nanoTime();
		estTime = (endTime - startTime) / 1000000000.0;
		System.out.println("Estimated time with basic sort: " + estTime + "\n");

		System.out.println("Sorting sequence with best pivot placement.");
		startTime = System.nanoTime();
		sorter2.quicksort(0, bestTestSet.length - 1);
		endTime = System.nanoTime();
		estTime = (endTime - startTime) / 1000000000.0;
		System.out.println("Estimated time: " + estTime);
		startTime = System.nanoTime();
		Arrays.sort(bestTestSet);
		endTime = System.nanoTime();
		estTime = (endTime - startTime) / 1000000000.0;
		System.out.println("Estimated time with basic sort: " + estTime + "\n");

		System.out.println("Sorting sequence with worst pivot placement.");
		startTime = System.nanoTime();
		sorter3.quicksort(0, worstTestSet.length - 1);
		endTime = System.nanoTime();
		estTime = (endTime - startTime) / 1000000000.0;
		System.out.println("Estimated time: " + estTime);
		startTime = System.nanoTime();
		Arrays.sort(worstTestSet);
		endTime = System.nanoTime();
		estTime = (endTime - startTime) / 1000000000.0;
		System.out.println("Estimated time with basic sort: " + estTime + "\n");
	}

	static void experiment3() {
		DataGenerator generator = new DataGenerator(maxBound);
		long startTime = 0, endTime = 0;
		double estTime = 0.0;

		// Lists for two subexperiments.
		SingleLinkedList list1 = generator.generateUnsortedLinkedList(10000);
		SingleLinkedList list2 = generator.generateUnsortedLinkedList(10000);
		// Chaining hash tables for two subexperiments.
		HashTable_Chaining bestCaseHT = generator.generateBestAverCaseChainingTable(10000);
		HashTable_Chaining worstCaseHT = generator.generateWorstCaseChainingTable(10000);
		
		

	}

	public static void main(String[] args) {
		// experiment1();
		// experiment2();
	}
}
