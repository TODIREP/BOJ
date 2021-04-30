fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val m = br.readLine().toInt()
    val stone = br.readLine().split(" ").map(String::toInt).toIntArray()
    val k = br.readLine().toInt()
    val total = stone.sum()
    var ans = 0.0

    for (it in 0 until m) {
        if (stone[it] < k) continue
        var temp = 1.0
        for (count in 0 until k) {
            temp *= (stone[it] - count).toDouble() / (total - count)
        }
        ans += temp
    }
    bw.write(String.format("%.15f", ans))
    bw.close()
}