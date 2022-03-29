## if (tea < 5 or candy < 5) -> bad
## if (tea > 2*candy or candy > 2*tea) -> great
## if (tea > 4 and candy > 4) -> good
##
import unittest


def tea_party (tea, candy):
  if (tea < 5 or candy < 5):
    return "bad"
  if (tea >= 2*candy or candy >= 2*tea):
    return "great"
  else:
    return "good"

def divide (numerator, denominator):
  if (denominator == 0):
    return 10000
  return numerator / denominator


class TeaPartyTest(unittest.TestCase):
    def setUp(self):
        """Call before every test case."""
        pass

    def tearDown(self):
        """Call after every test case."""
        pass

    def testGood(self):
        self.assertEqual(tea_party(5,6), "good")

    def testBad1(self):
        self.assertEqual(tea_party(4,6), "bad")

    def testBad2(self):
        self.assertEqual(tea_party(6,4), "bad")

    def testBad3(self):
        self.assertEqual(tea_party(4,4), "bad")

    def testGreat(self):
        self.assertEqual(tea_party(12,6), "great")

    def testGreat2(self):
        self.assertEqual(tea_party(6, 12), "great")

    def testWhatNow(self):
        self.assertEqual(tea_party(2, 4), "bad")

if __name__ == '__main__':
  ##print('5 / 4 = %.2f' % divide(5,4))
  #print('6 / 2 = %.2f' % divide(6,2))
  #print('4 / 3 = %.2f' % divide(4,3))
  #print('5 / 0 = %.2f' % divide(5,0)) ## this and the next line are in the same eqv. partition
  ##print('6 / 0 = %.2f' % divide(6,0))
  unittest.main()