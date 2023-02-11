import java.io.BufferedReader;
import java.util.Scanner;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static int R, C;
	static int[][] map;
	static boolean[] visit = new boolean[26];
	static int[] dx = { -1, 1, 0, 0 };
	static int[] dy = { 0, 0, -1, 1 };
	static int ans = 0;

	public static void dfs(int x, int y, int count) {
		if (visit[map[x][y]]) {
			ans = Math.max(ans, count);
		}
		else {
			visit[map[x][y]] = true;
			for (int i = 0; i < 4; i++) {
				int cx = x + dx[i];
				int cy = y + dy[i];

				if (cx >= 0 && cy >= 0 && cx < R && cy < C) {
					dfs(cx, cy, count + 1);
				}

			}

			visit[map[x][y]] = false;

		}
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		int[] testarr;
		testarr = new int[T];


		for (int test_case = 0; test_case < T; test_case++)
		{
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer st = new StringTokenizer(bf.readLine());

			R = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			map = new int[R][C];

			for (int i = 0; i < R; i++) {
				String str = bf.readLine();
				for (int j = 0; j < C; j++) {
					map[i][j] = str.charAt(j) - 'A';
				}
			}

			dfs(0, 0, 0);

			testarr[test_case] = ans;

		}

		sc.close();

		for (int test_case = 1; test_case <= T; test_case++) {

			System.out.print("#" + test_case + "  ");

			System.out.println(testarr[test_case - 1]);

		}
	}
}
