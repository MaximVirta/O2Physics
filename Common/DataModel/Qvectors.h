// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

///
/// \file   Qvectors.h
/// \author Cindy Mordasini <cindy.mordasini@cern.ch>
/// \author Anna Önnerstad <anna.onnerstad@cern.ch>
///
/// \brief  Declaration of the table for the (un)corrected Q-vectors for the event plane
/// determination.
///

#ifndef COMMON_DATAMODEL_QVECTORS_H_
#define COMMON_DATAMODEL_QVECTORS_H_

#include <vector>
#include "Framework/AnalysisDataModel.h"

namespace o2::aod
{
namespace qvec
{
DECLARE_SOA_COLUMN(Cent, cent, float);
DECLARE_SOA_COLUMN(IsCalibrated, isCalibrated, bool);

// Vector valued qvectors *************
DECLARE_SOA_COLUMN(QvecRe_vec, qvecRe_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecIm_vec, qvecIm_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecAmp, qvecAmp, std::vector<float>);

DECLARE_SOA_COLUMN(QvecFT0CRe_vec, qvecFT0CRe_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecFT0CIm_vec, qvecFT0CIm_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecFT0ARe_vec, qvecFT0ARe_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecFT0AIm_vec, qvecFT0AIm_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecFT0MRe_vec, qvecFT0MRe_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecFT0MIm_vec, qvecFT0MIm_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecFV0ARe_vec, qvecFV0ARe_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecFV0AIm_vec, qvecFV0AIm_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecBPosRe_vec, qvecBPosRe_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecBPosIm_vec, qvecBPosIm_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecBNegRe_vec, qvecBNegRe_vec, std::vector<float>);
DECLARE_SOA_COLUMN(QvecBNegIm_vec, qvecBNegIm_vec, std::vector<float>);


// Float valued qvectors **************
DECLARE_SOA_COLUMN(QvecRe, qvecRe, std::vector<float>);
DECLARE_SOA_COLUMN(QvecIm, qvecIm, std::vector<float>);

DECLARE_SOA_COLUMN(QvecFT0CRe, qvecFT0CRe, float);
DECLARE_SOA_COLUMN(QvecFT0CIm, qvecFT0CIm, float);
DECLARE_SOA_COLUMN(QvecFT0ARe, qvecFT0ARe, float);
DECLARE_SOA_COLUMN(QvecFT0AIm, qvecFT0AIm, float);
DECLARE_SOA_COLUMN(QvecFT0MRe, qvecFT0MRe, float);
DECLARE_SOA_COLUMN(QvecFT0MIm, qvecFT0MIm, float);
DECLARE_SOA_COLUMN(QvecFV0ARe, qvecFV0ARe, float);
DECLARE_SOA_COLUMN(QvecFV0AIm, qvecFV0AIm, float);
DECLARE_SOA_COLUMN(QvecBPosRe, qvecBPosRe, float);
DECLARE_SOA_COLUMN(QvecBPosIm, qvecBPosIm, float);
DECLARE_SOA_COLUMN(QvecBNegRe, qvecBNegRe, float);
DECLARE_SOA_COLUMN(QvecBNegIm, qvecBNegIm, float);

DECLARE_SOA_COLUMN(SumAmplFT0C, sumAmplFT0C, float);
DECLARE_SOA_COLUMN(SumAmplFT0A, sumAmplFT0A, float);
DECLARE_SOA_COLUMN(SumAmplFT0M, sumAmplFT0M, float);
DECLARE_SOA_COLUMN(SumAmplFV0A, sumAmplFV0A, float);
DECLARE_SOA_COLUMN(NTrkBPos, nTrkBPos, int);
DECLARE_SOA_COLUMN(NTrkBNeg, nTrkBNeg, int);
DECLARE_SOA_COLUMN(LabelsBPos, labelsBPos, std::vector<int>);
DECLARE_SOA_COLUMN(LabelsBNeg, labelsBNeg, std::vector<int>);
} // namespace qvec

DECLARE_SOA_TABLE(Qvectors_vec, "AOD", "QVECTORDEVS_V", //! Table with all Qvectors.
                  qvec::Cent, qvec::IsCalibrated, qvec::QvecRe_vec, qvec::QvecIm_vec, qvec::QvecAmp);
using Qvector_vec = Qvectors_vec::iterator;

DECLARE_SOA_TABLE(Qvectors, "AOD", "QVECTORDEVS", //! Table with all Qvectors.
                  qvec::Cent, qvec::IsCalibrated, qvec::QvecRe, qvec::QvecIm, qvec::QvecAmp);
using Qvector = Qvectors::iterator;

// Vector valued qvectors
DECLARE_SOA_TABLE(QvectorFT0Cs_vec, "AOD", "QVECTORSFT0C_V", qvec::IsCalibrated, qvec::QvecFT0CRe_vec, qvec::QvecFT0CIm_vec, qvec::SumAmplFT0C);
DECLARE_SOA_TABLE(QvectorFT0As_vec, "AOD", "QVECTORSFT0A_V", qvec::IsCalibrated, qvec::QvecFT0ARe_vec, qvec::QvecFT0AIm_vec, qvec::SumAmplFT0A);
DECLARE_SOA_TABLE(QvectorFT0Ms_vec, "AOD", "QVECTORSFT0M_V", qvec::IsCalibrated, qvec::QvecFT0MRe_vec, qvec::QvecFT0MIm_vec, qvec::SumAmplFT0M);
DECLARE_SOA_TABLE(QvectorFV0As_vec, "AOD", "QVECTORSFV0A_V", qvec::IsCalibrated, qvec::QvecFV0ARe_vec, qvec::QvecFV0AIm_vec, qvec::SumAmplFV0A);
DECLARE_SOA_TABLE(QvectorBPoss_vec, "AOD", "QVECTORSBPOS_V", qvec::IsCalibrated, qvec::QvecBPosRe_vec, qvec::QvecBPosIm_vec, qvec::NTrkBPos, qvec::LabelsBPos);
DECLARE_SOA_TABLE(QvectorBNegs_vec, "AOD", "QVECTORSBNEG_V", qvec::IsCalibrated, qvec::QvecBNegRe_vec, qvec::QvecBNegIm_vec, qvec::NTrkBNeg, qvec::LabelsBNeg);

using QvectorFT0C_vec = QvectorFT0Cs_vec::iterator;
using QvectorFT0A_vec = QvectorFT0As_vec::iterator;
using QvectorFT0M_vec = QvectorFT0Ms_vec::iterator;
using QvectorFV0A_vec = QvectorFV0As_vec::iterator;
using QvectorBPos_vec = QvectorBPoss_vec::iterator;
using QvectorBNeg_vec = QvectorBNegs_vec::iterator;

// Float valued qvectors
DECLARE_SOA_TABLE(QvectorFT0Cs, "AOD", "QVECTORSFT0C", qvec::IsCalibrated, qvec::QvecFT0CRe, qvec::QvecFT0CIm, qvec::SumAmplFT0C);
DECLARE_SOA_TABLE(QvectorFT0As, "AOD", "QVECTORSFT0A", qvec::IsCalibrated, qvec::QvecFT0ARe, qvec::QvecFT0AIm, qvec::SumAmplFT0A);
DECLARE_SOA_TABLE(QvectorFT0Ms, "AOD", "QVECTORSFT0M", qvec::IsCalibrated, qvec::QvecFT0MRe, qvec::QvecFT0MIm, qvec::SumAmplFT0M);
DECLARE_SOA_TABLE(QvectorFV0As, "AOD", "QVECTORSFV0A", qvec::IsCalibrated, qvec::QvecFV0ARe, qvec::QvecFV0AIm, qvec::SumAmplFV0A);
DECLARE_SOA_TABLE(QvectorBPoss, "AOD", "QVECTORSBPOS", qvec::IsCalibrated, qvec::QvecBPosRe, qvec::QvecBPosIm, qvec::NTrkBPos, qvec::LabelsBPos);
DECLARE_SOA_TABLE(QvectorBNegs, "AOD", "QVECTORSBNEG", qvec::IsCalibrated, qvec::QvecBNegRe, qvec::QvecBNegIm, qvec::NTrkBNeg, qvec::LabelsBNeg);

using QvectorFT0C = QvectorFT0Cs::iterator;
using QvectorFT0A = QvectorFT0As::iterator;
using QvectorFT0M = QvectorFT0Ms::iterator;
using QvectorFV0A = QvectorFV0As::iterator;
using QvectorBPos = QvectorBPoss::iterator;
using QvectorBNeg = QvectorBNegs::iterator;

} // namespace o2::aod

#endif // COMMON_DATAMODEL_QVECTORS_H_
