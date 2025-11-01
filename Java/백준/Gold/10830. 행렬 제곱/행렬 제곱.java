import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        long B = Long.parseLong(st.nextToken());
        B-=1;
        int[][] arr = new int[N][N];
        for(int i = 0; i < N; i++) {st = new StringTokenizer(br.readLine());for(int j = 0; j < N; j++) arr[i][j] = Integer.parseInt(st.nextToken()) % 1000;}
        int[][] res = new int[N][N];
        for(int i = 0; i < N; i++) res[i] = Arrays.copyOf(arr[i],N);

        while(B>0) {
            long t = B%2;
            if(t==1) {
                res = mat(arr,res);
            }
            B/=2;
            arr = mat(arr,arr);
        }

        for(int[] n: res) {
            for (int m : n) bw.write(m + " ");
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
    static int[][] mat(int[][] a,int[][] b) {
        int[][] r = new int[N][N];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                int sum = 0;
                for(int k = 0; k < N; k++) {
                    sum += a[i][k] * b[k][j];
                    sum%=1000;
                }
                r[i][j] = sum;
            }
        }
        return r;
    }
}