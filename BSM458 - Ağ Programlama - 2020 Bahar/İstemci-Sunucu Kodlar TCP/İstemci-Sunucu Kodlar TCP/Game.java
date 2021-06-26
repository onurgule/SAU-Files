import java.util.Arrays;

public class Game {
public int Play1(String str) {
if(str.length() != 10) return -1;
char[] bh = str.substring(1).toCharArray();
int []sh = new int[bh.length];
int index=0;
for(var b : bh) {
sh[index++] = Character.getNumericValue(b);
}
int a = (int)Arrays.stream(sh).average().getAsDouble();
a = 3;
return Arrays.stream(sh).sum()/a;
}
public static void main(String[] args) {
	Game g = new Game();
	String ogr = "G171210021";
	System.out.println(g.Play1(ogr));
}
}