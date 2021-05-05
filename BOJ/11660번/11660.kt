import java.util.*
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    var token = StringTokenizer(br.readLine())
    val n = token.nextToken().toInt()
    val m = token.nextToken().toInt()
    val arr = Array(n + 1) { IntArray(n + 1) { 0 } }
    for (x in 1..n) {
        token = StringTokenizer(br.readLine())
        for (y in 1..n) arr[x][y] = token.nextToken().toInt() + arr[x][y - 1]
        for (y in 1..n) arr[x][y] += arr[x - 1][y]
    }
    for (it in 1..m) {
        token = StringTokenizer(br.readLine())
        val x1 = token.nextToken().toInt() - 1
        val y1 = token.nextToken().toInt() - 1
        val x2 = token.nextToken().toInt()
        val y2 = token.nextToken().toInt()
        bw.write("${arr[x2][y2] - (arr[x1][y2] + arr[x2][y1] - arr[x1][y1])}\n")
    }
    bw.close()
}