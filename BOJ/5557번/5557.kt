fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val res = Array(n) { LongArray(21) { 0L } }
    var target = 0
    br.readLine().split(" ").map(String::toInt).forEachIndexed { index, value ->
        when (index) {
            0 -> res[index][value] = 1L
            n - 1 -> target = value
            else -> {
                for (prev in 0..20) {
                    if (res[index - 1][prev] != 0L) {
                        if (prev + value <= 20) res[index][prev + value] += res[index - 1][prev]
                        if (prev - value >= 0) res[index][prev - value] += res[index - 1][prev]
                    }
                }
            }
        }
    }
    bw.write("${res[n - 2][target]}")
    bw.close()
}