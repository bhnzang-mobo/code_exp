package exp;

import exp2.*;//exp2 package has test4, test5 class

public class test1 extends test5 { // /**/ parts can be eliminated if you want to access to test5_proc method.
	public static void main (String[] args) {
		test2 hi = new test2();
		hi.hello();
		hi.setname("MOBO");
		System.out.println(hi.name);
		
		test3 hi2 = new test2(); //test2 extends test3
		System.out.println(hi2.mobo());
		
		test4 hi3 = new test4();//test4 is outer class, default class can not be accessed.
		System.out.println(hi3.mobo);
		hi3.test5_publ();
		/*hi3.test5_proc();*/
		
		test5 hi5 = new test5();
		hi5.test5_publ();
		/*hi5.test5_proc();*/
	}
}
