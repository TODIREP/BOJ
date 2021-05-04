import java.util.*
fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    val inDegree = IntArray(n) { 0 }
    val outDegree = Array(n) { mutableListOf<Int>() }
    val build = IntArray(n)
    val res = IntArray(n) { 0 }
    for (it in 0 until n) {
        val token = StringTokenizer(br.readLine())
        build[it] = token.nextToken().toInt()
        while (true) {
            val prev = token.nextToken().toInt()
            if (prev == -1) break
            inDegree[it]++
            outDegree[prev - 1].add(it)
        }
    }
    val queue: Queue<Int> = LinkedList()
    for (it in 0 until n) if (inDegree[it] == 0) {
        queue.add(it)
        res[it] = build[it]
    }
    while (queue.isNotEmpty()) {
        val cur = queue.remove()
        outDegree[cur].forEach {
            res[it] = res[it].coerceAtLeast(res[cur] + build[it])
            if (--inDegree[it] == 0) queue.add(it)
        }
    }
    for (it in 0 until n) print("${res[it]}\n")
}