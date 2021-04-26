fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val pre = br.readLine().split(" ").map(String::toInt).toIntArray()
    val max = IntArray(3)
    val min = IntArray(3)
    for (it in 0 until 3) {
        max[it] = pre[it]
        min[it] = pre[it]
    }
    for (case in 1 until n) {
        val num = br.readLine().split(" ").map(String::toInt).toIntArray()
        val tempMax = IntArray(3) { -1 }
        val tempMin = IntArray(3) { 1e9.toInt() }

        for (index in 0 until 3) {
            for (diff in -1 until 2) {
                val next = index + diff
                if ((next < 0) || (next > 2)) continue
                tempMax[next] = tempMax[next].coerceAtLeast(max[index] + num[next])
                tempMin[next] = tempMin[next].coerceAtMost(min[index] + num[next])
            }
        }
        for (it in 0 until 3) {
            max[it] = tempMax[it]
            min[it] = tempMin[it]
        }
    }
    var ansMax = -1
    var ansMin = 1e9.toInt()
    for (it in 0 until 3) {
        ansMax = ansMax.coerceAtLeast(max[it])
        ansMin = ansMin.coerceAtMost(min[it])
    }
    bw.write("$ansMax $ansMin")
    bw.close()
}