package exp;

public class test2 implements test3{
	String name;
	protected void hello() {
		System.out.println("hello world");
	}
	public void setname(String inp) {//메소드가 main 처럼 static일 필요는 없다!
		this.name=inp;
	}
	public String mobo() {
		return "SKKU_MOBO";
	}
}
