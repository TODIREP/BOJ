fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (k, n) = br.readLine().split(" ").map(String::toInt)
    val cable = LongArray(k)
    var left: Long = 1
    var right: Long = 0
    repeat(k) {
        cable[it] = br.readLine().toLong()
        right = right.coerceAtLeast(cable[it])
    }
    var answer: Long = 0
    while (left <= right) {
        val mid = (left + right) / 2

        var count: Long = 0
        repeat(k) { count += cable[it] / mid }

        if (count >= n) {
            answer = answer.coerceAtLeast(mid)
            left = mid + 1
        } else right = mid - 1
    }
    bw.write("$answer")
    bw.close()
}