import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(bf.readLine());
        long[][] c = {{1,1},{1,0}};
        long[][] arr = {{1,1},{1,0}};
        while(n>0) {
            if (n%2 == 1) {
                arr = gob(arr,c);
            }
            c = gob(c,c);
            n/=2;
        }

        System.out.println(arr[1][1]);
    }

    public static long[][] gob(long[][] a, long[][] b) {
        long[][] arr = new long[2][2];
        arr[0][0] = (a[0][0]*b[0][0]%Z + a[0][1]*b[1][0]%Z)%Z;
        arr[0][1] = (a[0][0]*b[0][1]%Z + a[0][1]*b[1][1]%Z)%Z;
        arr[1][0] = (a[1][0]*b[0][0]%Z + a[1][1]*b[1][0]%Z)%Z;
        arr[1][1] = (a[1][0]*b[0][1]%Z + a[1][1]*b[1][1]%Z)%Z;

        return arr;
    }
    public static final int Z = 1000000007;
}