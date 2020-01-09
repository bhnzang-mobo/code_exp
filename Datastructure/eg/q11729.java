import java.util.*;
import java.math.*;

public class q11729 {
	public static void hanoi(int num, int from, int by, int to){
		if(num==1){
		System.out.printf("%d %d\n",from,to);
		return;
		}
		hanoi(num-1,from,to,by);
		System.out.printf("%d %d\n",from,to);
		hanoi(num-1,by,from,to);
	}

	public static void main(String args[]){
	    int num;
	    Scanner sc = new Scanner(System.in);
	    num=sc.nextInt();
	    System.out.printf("%d \n",(int)Math.pow(2,num)-1);
		hanoi(num,1,2,3);
	}
}
