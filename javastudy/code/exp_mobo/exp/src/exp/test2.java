package exp;

public class test2 implements test3{
	String name;
	protected void hello() {
		System.out.println("hello world");
	}
	public void setname(String inp) {//�޼ҵ尡 main ó�� static�� �ʿ�� ����!
		this.name=inp;
	}
	public String mobo() {
		return "SKKU_MOBO";
	}
}
