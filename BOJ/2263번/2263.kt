import java.util.*
fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()

    var token = StringTokenizer(br.readLine())
    val inOrder = IntArray(n)
    for (it in 0 until n) inOrder[it] = token.nextToken().toInt()

    token = StringTokenizer(br.readLine())
    val postOrder = IntArray(n)
    for (it in 0 until n) postOrder[it] = token.nextToken().toInt()

    val rootIndex = IntArray(n)
    for (it in 0 until n) rootIndex[inOrder[it] - 1] = it

    val result = StringBuilder()
    fun order(inLeft: Int, inRight: Int, postLeft: Int, postRight: Int) {
        if (inLeft > inRight || postLeft > postRight) return
        val rootNode = postOrder[postRight]
        result.append("$rootNode ")
        val rootIdx = rootIndex[rootNode - 1]
        order(inLeft, rootIdx - 1, postLeft, postLeft + rootIdx - inLeft - 1)
        order(rootIdx + 1, inRight, postLeft + rootIdx - inLeft, postRight - 1)
    }
    order(0, n - 1, 0, n - 1)
    print(result.toString())
}