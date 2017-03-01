#ifndef TOOLHISTOGRAMEQUALIZATIONERMAINDIALOG_H
#define TOOLHISTOGRAMEQUALIZATIONERMAINDIALOG_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <vector>
#include <QImage>
#pragma GCC diagnostic pop

struct QImage;

namespace ribi {

struct HistogramEqualizationerMainDialog
{
  static QImage DoHistogramEqualization(const QImage& source) noexcept;

  private:
  //void ConvertToGrey(const TImage * const source, TImage * const target);
  static const std::vector<int> GetImageHistogram(const QImage& image) noexcept;

  #ifndef NDEBUG
  static void Test() noexcept;
  #endif
};

//From htpp://www.richelbilderbeek.nl/CppGetCumulativeHistogram.htm
template <class T> const std::vector<T> GetCumulativeHistogram(const std::vector<T>& histogram)
{
  std::vector<T> v(histogram.begin(),histogram.end() );
  const int size = v.size();
  for (int i=1; i!=size; ++i)
  {
    v[i] += v[i-1];
  }
  return v;
}

} //~namespace ribi


#endif
