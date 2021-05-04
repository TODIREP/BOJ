import java.util.*
data class Node(val start: Int, val dis: Int): Comparable<Node> {
    override fun compareTo(other: Node) = if (dis < other.dis) -1 else 1
}
fun main() {
    val br = System.`in`.bufferedReader()
    fun input() = br.readLine().split(" ").map(String::toInt)
    val limit = 1e9.toInt()
    val (v, e) = input()
    val k = input()[0] - 1
    val distance = IntArray(v) { limit }
    val link = Array(v) { mutableListOf<Node>() }
    for (it in 0 until e) {
        val (a, b, c) = input()
        link[a - 1].add(Node(b - 1, c))
    }
    val queue = PriorityQueue<Node>()
    distance[k] = 0
    queue.add(Node(k, distance[k]))

    while (queue.isNotEmpty()) {
        val curStart = queue.peek().start
        val curWeight = queue.remove().dis

        if (curWeight != distance[curStart]) continue
        link[curStart].forEach {
            val nextWeight = curWeight + it.dis
            if (nextWeight < distance[it.start]) {
                distance[it.start] = nextWeight
                queue.add(Node(it.start, distance[it.start]))
            }
        }
    }
    for (it in 0 until v) print("${if (distance[it] == limit) "INF" else distance[it]}\n")
}