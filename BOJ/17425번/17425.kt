fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val ans = LongArray(1000001) { 0 }
    for (a in 1..1000000) for (b in a..1000000 step a) ans[b] += a.toLong()
    for (a in 2..1000000) ans[a] += ans[a - 1]
    val n = br.readLine().toInt()
    for (a in 1..n) bw.write("${ans[br.readLine().toInt()]}\n")
    bw.close()
}