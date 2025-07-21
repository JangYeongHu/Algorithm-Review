import java.io.*;

public class Main {
    static int[] arr;
    static int s,cnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        s = Integer.parseInt(bf.readLine());
        arr = new int[s];
        queen(0);
        System.out.println(cnt);
    }
    public static void queen(int n) {
        if(n == s) {
            cnt++;
            return;
        }
        for(int i = 0; i < s; i++) {
            arr[n] = i;
            if(check(n)) continue;
            queen(n + 1);
        }
    }
    public static boolean check(int n) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == arr[n] || Math.abs(n - i) == Math.abs(arr[n] - arr[i])) return true;
        }
        return false;
    }
}