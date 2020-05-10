package exp2;

public class test4 extends test5{ 
	//if this class is declared as default(no access modifier), test1.java, which has imported test4.java, is not visible to test4.java
	public String mobo="I'm from another package"; //
	public static void main() {
		test5 hi5 = new test5();
		hi5.test5_default();
		hi5.test5_proc(); //if you want to use this method, do extend test5
		
	}
}
