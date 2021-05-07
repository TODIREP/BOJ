fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    val n = readLine().toInt()
    val stair = IntArray(n)
    for (it in 0 until n) stair[it] = readLine().toInt()
    val ans = Array(n + 1) { IntArray(2) { 0 } }
    ans[1][0] = stair[0]
    for (it in 2..n) {
        ans[it][0] = ans[it - 2][0].coerceAtLeast(ans[it - 2][1]) + stair[it - 1]
        ans[it][1] = ans[it - 1][0] + stair[it - 1]
    }
    bw.write("${ans[n][0].coerceAtLeast(ans[n][1])}")
    bw.close()
}