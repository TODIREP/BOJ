import java.util.*
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (n, m) = br.readLine().split(" ").map(String::toInt)
    val inDegree = IntArray(m) { 0 }
    val link = Array(n) { mutableListOf<Int>() }
    val water = IntArray(m)
    for (it in 0 until m) {
        val token = StringTokenizer(br.readLine())
        val k = token.nextToken().toInt()
        val outDegree = IntArray(k)
        for (out in 0 until k) outDegree[out] = token.nextToken().toInt()
        val target = token.nextToken().toInt()
        water[it] = target - 1
        for (out in 0 until k) {
            link[outDegree[out] - 1].add(it)
            inDegree[it]++
        }
    }
    val queue: Queue<Int> = LinkedList()
    br.readLine().toInt()
    var count = 0
    val check = BooleanArray(n) { false }
    br.readLine().split(" ").map(String::toInt).forEach { start ->
        check[start - 1] = true
        queue.add(start - 1)
        count++
    }
    while (queue.isNotEmpty()) {
        val cur = queue.remove()
        for (next in link[cur]) {
            val nextWater = water[next]
            inDegree[next]--
            if (inDegree[next] == 0 && !check[nextWater]) {
                check[nextWater] = true
                queue.add(nextWater)
                count++
            }
        }
    }
    bw.write("$count\n")
    for (it in 0 until n) {
        if (check[it]) bw.write("${it + 1} ")
    }
    bw.close()
}