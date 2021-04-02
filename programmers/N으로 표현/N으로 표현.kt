import java.util.*
class Solution {
    fun solution(N: Int, number: Int): Int {
        val num = Array(9) { TreeSet<Int>() }
        
        var curNum = 0
        for (x in 1 until 9) {
            curNum += N
            num[x].add(curNum)
            curNum *= 10
        }
        
        for (x in 1 until 9) {
            for (y in 1 until x + 1) {
                if (x + y <= 8) {
                    for (xN in num[x]) {
                        for (yN in num[y]) {
                            intArrayOf(xN * yN, xN + yN, Math.abs(xN - yN), xN / yN).forEach { nxtNum ->
                                if (nxtNum != 0) {
                                    num[x + y].add(nxtNum)
                                }
                            }
                        }
                    }
                }
            }
        }
        
        for (x in 1 until 9) {
            for (res in num[x]) {
                if (res == number) {
                    return x
                }
            }
        }
        return -1
    }
}