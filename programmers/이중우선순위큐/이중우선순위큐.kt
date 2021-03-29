import java.util.*

class Solution {
    fun solution(operations: Array<String>): IntArray {
        var answer = intArrayOf(0, 0)
        var cnt = 0
        val minHeap = PriorityQueue<Int>()
        val maxHeap = PriorityQueue<Int>(reverseOrder())
        
        for (operation in operations) {
            val (op, num) = operation.split(" ")
            val number = num.toInt()
            
            when (op) {
                "I" -> {
                    minHeap.add(number)
                }
                else -> {
                    when (number) {
                        1 -> {
                            while (minHeap.isNotEmpty()) {
                                maxHeap.add(minHeap.remove())
                            }
                            if (maxHeap.isNotEmpty()) {
                                maxHeap.remove()
                            }
                        }
                        else -> {
                            while (maxHeap.isNotEmpty()) {
                                minHeap.add(maxHeap.remove())
                            }
                            if (minHeap.isNotEmpty()) {
                                minHeap.remove()
                            }
                        }
                    }
                }
            }
        }
        
        while (minHeap.isNotEmpty()) {
            maxHeap.add(minHeap.remove())
        }
        if (maxHeap.isNotEmpty()) {
            cnt++
            answer[0] = maxHeap.remove()
        }
        
        while (maxHeap.isNotEmpty()) {
            minHeap.add(maxHeap.remove())
        }
        if (minHeap.isNotEmpty()) {
            cnt++
            answer[1] = minHeap.remove()
        }
        return if (cnt == 2) answer else intArrayOf(0, 0)
    }
}