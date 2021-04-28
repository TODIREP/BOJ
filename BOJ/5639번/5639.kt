fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val node = mutableListOf<Int>()
    while (true) {
        val input = br.readLine() ?: break
        node.add(input.toInt())
    }
    val link = Array(node.size) { IntArray(2) { -1 } }
    fun search(start: Int, end: Int) {
        if (start + 1 == end) return
        var right = end
        for (index in start until end) {
            if (node[index] > node[start]) {
                right = index
                break
            }
        }
        if (node[start + 1] < node[start]) {
            link[start][0] = start + 1
            search(start + 1, right)
        }
        if (right < end) {
            link[start][1] = right
            search(right, end)
        }
    }
    search(0, node.size)
    fun postOrder(cur: Int) {
        if (link[cur][0] != -1) postOrder(link[cur][0])
        if (link[cur][1] != -1) postOrder(link[cur][1])
        bw.write("${node[cur]}\n")
    }
    postOrder(0)
    bw.close()
}