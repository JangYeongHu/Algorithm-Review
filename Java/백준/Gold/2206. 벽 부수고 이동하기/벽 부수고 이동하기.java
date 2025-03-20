import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int[] dx = {-1,1,0,0}, dy = {0,0,1,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        int INF = 1<<30;
        int[][] arr = new int[N][M];
        int[][][] vi = new int[N][M][2];
        for(int i = 0; i < N; i++)for(int j = 0; j < M; j++)Arrays.fill(vi[i][j],INF);
        for(int i = 0; i < N; i++) arr[i] = Arrays.stream(br.readLine().split("")).mapToInt(Integer::parseInt).toArray();
        vi[0][0][0] = 1;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0,0,0});
        while(!queue.isEmpty()) {
            int[] t=queue.poll();
            for(int i = 0; i < 4; i ++) {
                int x = t[0] + dx[i],y = t[1] + dy[i], c = t[2];
                if(x < 0 || x >= M || y < 0 || y >= N) continue;
                if(vi[y][x][c] != INF) continue;
                if(c == 1) {
                    if(arr[y][x] == 1) continue;
                    queue.add(new int[]{x,y,1});
                    vi[y][x][1] = vi[t[1]][t[0]][1] + 1;
                } else {
                    if(arr[y][x] == 1) {
                        queue.add(new int[]{x,y,1});
                        vi[y][x][1] = vi[t[1]][t[0]][0] + 1;
                    } else {
                        queue.add(new int[]{x,y,0});
                        vi[y][x][0] = vi[t[1]][t[0]][0] + 1;
                    }
                }
            }
        }
        int m = Math.min(vi[N-1][M-1][0],vi[N-1][M-1][1]);
        if(m == INF) System.out.println(-1);
        else System.out.println(m);
    }
}