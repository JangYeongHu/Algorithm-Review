import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int n = Integer.parseInt(br.readLine()),cnt = 0;
        while(n-->0) pq.add(Integer.parseInt(br.readLine()));
        while(true) {
            int a = pq.poll();
            if(pq.isEmpty()) {
                System.out.println(cnt);
                break;
            }
            int b = pq.poll();
            cnt += a+b;
            pq.add(a+b);
        }
    }
}