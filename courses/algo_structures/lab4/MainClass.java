package com.maxdev.lab4asd;

public class MainClass {

	private static BinaryTree prepBinaryTree() {
		// Binary tree for tests.
		BinaryTree testTree = new BinaryTree();
		// Prepare testing set for tree testing.
		Student[] studentSet = new Student[11];
		int[] idSet = { 50, 45, 20, 48, 60, 55, 70, 65, 68, 67, 69 };
		for (int i = 0; i < studentSet.length; i++) {
			studentSet[i] = new Student("testName", "testSurname", i, idSet[i], 5, true);
		}
		// Add students set to the tree.
		for (int i = 0; i < studentSet.length; i++) {
			testTree.insert(studentSet[i]);
		}
		return (testTree);
	}

	private static void test1(BinaryTree testTree) {
		System.out.println("----------------------------->>> Binary tree test 1 <<<-----------------------------");
		
		System.out.println("Size of the tree: " + testTree.size());
		System.out.println("");
		
		System.out.println("In-order traverse: ");
		testTree.traverse();
		System.out.println("");
		
		System.out.println("Level-order traverse: ");
		
		System.out.println("----------------------------->>> End of binary tree test 1 <<<-----------------------------");
	}

	public static void main(String[] args) {

		BinaryTree testTree = prepBinaryTree();
		test1(testTree);

	}
}
