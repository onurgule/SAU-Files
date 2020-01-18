package paket;
/**
*
* @author Fatih
*/
public class Sayi {
	private int deger;
	private boolean eksimi;
	
	public Sayi(int deger){
		this.deger = deger;
		eksimi = deger < 0;
	}
	Sayi(){
		
	}
	void ad2(){ //yok
		
	}
	void ad23() { //yok
		
	}
	void ad3(int pr2)
	{
		
	}
	void ad4(int pr1, double pr2){
		
	}
	void ad5(int pr1, double pr2)
	{
		
	}
	private void ad21(){
		
	}
	public void ad31(int pr2)
	{
		
	}
	public void ad41(int pr1, double pr2){
		
	}
	public void ad51(int pr1, double pr2)
	{
		
	}
	public static void ad22(){
		
	}
	public static void ad32(int pr2)
	{
		for(int i = 1; i<20;i++){
			
		}
	}
	public static String ad42(int pr1,double pr2, int pr3,int pr4){
		
	}
	private static double ad52(int pr1, double pr2)
	{
		
	}
	private int deee;
	public void setDeger(int value){
		this.deger = value;
		eksimi = this.deger < 0;
	}
	public boolean Eksimi(){
		return eksimi;
	}
	
	@Override
	public String toString() {
		return String.valueOf(deger);
	}
}