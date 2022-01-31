# wordleのためのDP
5語で25文字の英文字をかぶりなくカバーするための組み合わせを列挙するものです．

bitDPというアルゴリズムを用いて実装しています．<img src="https://latex.codecogs.com/svg.image?c" title="c=26" />を英小文字の種類数つまり<img src="https://latex.codecogs.com/svg.image?c=26" title="c=26" />としたとき，単語の種類数<img src="https://latex.codecogs.com/svg.image?N" title="c=26" />に対して<img src="https://latex.codecogs.com/svg.image?O(2^cN)" title="O(2^cN)" />オーダーの時間で列挙が可能です．
