fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val link = Array(26) { IntArray(2) { -1 } }
    for (it in 0 until n) {
        val node = br.readLine()
        if (node[2] != '.') link[node[0] - 'A'][0] = node[2] - 'A'
        if (node[4] != '.') link[node[0] - 'A'][1] = node[4] - 'A'
    }
    fun preOrder(cur: Int) {
        bw.write("${cur.toChar() + 'A'.toInt()}")
        if (link[cur][0] != -1) preOrder(link[cur][0])
        if (link[cur][1] != -1) preOrder(link[cur][1])
    }
    preOrder(0)
    bw.write("\n")
    fun inOrder(cur: Int) {
        if (link[cur][0] != -1) inOrder(link[cur][0])
        bw.write("${cur.toChar() + 'A'.toInt()}")
        if (link[cur][1] != -1) inOrder(link[cur][1])
    }
    inOrder(0)
    bw.write("\n")
    fun postOrder(cur: Int) {
        if (link[cur][0] != -1) postOrder(link[cur][0])
        if (link[cur][1] != -1) postOrder(link[cur][1])
        bw.write("${cur.toChar() + 'A'.toInt()}")
    }
    postOrder(0)
    bw.write("\n")
    bw.close()
}