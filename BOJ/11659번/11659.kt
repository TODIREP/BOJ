import java.util.*
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    fun scan(token: StringTokenizer) = token.nextToken().toInt()
    var token = StringTokenizer(br.readLine())
    val (n, m) = intArrayOf(scan(token), scan(token))
    val arr = IntArray(n + 1) { 0 }
    token = StringTokenizer(br.readLine())
    for (it in 1..n) arr[it] = scan(token)
    for (it in 1..n) arr[it] += arr[it - 1]
    for (it in 0 until m) {
        token = StringTokenizer(br.readLine())
        val (i, j) = intArrayOf(scan(token), scan(token))
        bw.write("${arr[j] - arr[i - 1]}\n")
    }
    bw.close()
}