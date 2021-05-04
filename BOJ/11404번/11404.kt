import java.util.*
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val limit = 1e9.toInt()
    val n = br.readLine().toInt()
    val dis = Array(n) { IntArray(n) { limit } }
    val m = br.readLine().toInt()
    for (it in 0 until m) {
        val token = StringTokenizer(br.readLine())
        val a = token.nextToken().toInt() - 1
        val b = token.nextToken().toInt() - 1
        val c = token.nextToken().toInt()
        dis[a][b] = dis[a][b].coerceAtMost(c)
    }
    for (check in 0 until n) {
        for (front in 0 until n) {
            if (front == check) continue
            for (back in 0 until n) {
                if (back == front || back == check) continue
                dis[front][back] = dis[front][back].coerceAtMost(dis[front][check] + dis[check][back])
            }
        }
    }
    for (x in 0 until n) {
        for (y in 0 until n) bw.write("${if (dis[x][y] == limit) 0 else dis[x][y]} ")
        bw.write("\n")
    }
    bw.close()
}