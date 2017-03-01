#include "qthistogramequalizationermaindialog.h"

void ribi::QtHistogramEqualizationerMainDialog::Test() noexcept
{
  const QImage source(":/histogramequalizationer/images/ToolHistogramEqualizationerTest.png");
  assert(!source.isNull());
  const QImage target {

    HistogramEqualizationerMainDialog::DoHistogramEqualization(source)
  };
  assert(!target.isNull());
  assert(target != source);
  const QImage target_again {
    HistogramEqualizationerMainDialog::DoHistogramEqualization(source)
  };
  assert(!target_again.isNull());
  assert(target == target_again
    && "A second histogram equalization will result in the original");
}
