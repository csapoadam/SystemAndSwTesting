import unittest


def grade_score (score):
    if (score > 100):
        raise Exception('Value overflow')
    elif (score >= 90):
        return "A"
    elif (score > 79):
        return "B"
    elif (score > 69):
        return "C"
    elif (score > 59):
        return "D"
    elif (score > 49):
        return "D-"
    elif (score > 0):
        return "F"
    else:
        raise Exception('Value underflow')


class GradeScoreBoundaryValuesTest(unittest.TestCase):
    def setUp(self):
        """Call before every test case."""
        pass

    def tearDown(self):
        """Call after every test case."""
        pass

    def testBorderTopAOverflow(self):
        with self.assertRaises(Exception) as context:
            grade_score(101)
        self.assertTrue('Value overflow' in str(context.exception))

    def testBorderBottomFUnderflow(self):
        with self.assertRaises(Exception) as context:
            grade_score(0)
        self.assertTrue('Value underflow' in str(context.exception))


    def testBorderTopA(self):
        self.assertEqual(grade_score(100), "A")

    def testBorderBottomA(self):
        self.assertEqual(grade_score(90), "A")

    def testBorderTopB(self):
        self.assertEqual(grade_score(89), "B")

    def testBorderTopB2(self):
        self.assertEqual(grade_score(89.5), "B") ## what about floating point inputs?

    def testBorderBottomB(self):
        self.assertEqual(grade_score(80), "B")

    def testBorderTopC(self):
        self.assertEqual(grade_score(79), "C")

    def testBorderBottomC(self):
        self.assertEqual(grade_score(70), "C")

    def testBorderTopD(self):
        self.assertEqual(grade_score(69), "D")

    def testBorderBottomD(self):
        self.assertEqual(grade_score(60), "D")

    def testBorderTopDm(self):
        self.assertEqual(grade_score(59), "D-")

    def testBorderBottomDm(self):
        self.assertEqual(grade_score(50), "D-")

    def testBorderTopF(self):
        self.assertEqual(grade_score(49), "F")

    def testBorderBottomF(self):
        self.assertEqual(grade_score(1), "F")


if __name__ == '__main__':
    ##print('5 / 4 = %.2f' % divide(5,4))
    #print('6 / 2 = %.2f' % divide(6,2))
    #print('4 / 3 = %.2f' % divide(4,3))
    #print('5 / 0 = %.2f' % divide(5,0)) ## this and the next line are in the same eqv. partition
    ##print('6 / 0 = %.2f' % divide(6,0))
    unittest.main()