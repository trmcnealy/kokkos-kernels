/*
//@HEADER
// ************************************************************************
//
//               KokkosKernels 0.9: Linear Algebra and Graph Kernels
//                 Copyright 2017 Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Siva Rajamanickam (srajama@sandia.gov)
//
// ************************************************************************
//@HEADER
*/

#ifndef KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_HPP_
#define KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_HPP_

namespace KokkosBlas {
namespace Impl {
// Specialization struct which defines whether a specialization exists
template<class XMV, class YMV, int rank = YMV::rank>
struct copy_tpl_spec_avail {
  enum : bool { value = false };
};
}
}

namespace KokkosBlas {
namespace Impl {

// Generic Host side BLAS (could be MKL or whatever)
#ifdef KOKKOSKERNELS_ENABLE_TPL_BLAS

#define KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( SCALAR, LAYOUTX, LAYOUTY, MEMSPACE ) \
template<class ExecSpace> \
struct copy_tpl_spec_avail< \
Kokkos::View<const SCALAR*, LAYOUTX, Kokkos::Device<ExecSpace, MEMSPACE>, \
             Kokkos::MemoryTraits<Kokkos::Unmanaged> >, \
Kokkos::View<SCALAR*, LAYOUTY, Kokkos::Device<ExecSpace, MEMSPACE>, \
             Kokkos::MemoryTraits<Kokkos::Unmanaged> >, \
1> { enum : bool { value = true }; };

#if defined (KOKKOSKERNELS_INST_DOUBLE)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( double,                  Kokkos::LayoutLeft, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( double,                  Kokkos::LayoutLeft, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( double,                  Kokkos::LayoutLeft, Kokkos::LayoutStride, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( double,                  Kokkos::LayoutRight, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( double,                  Kokkos::LayoutRight, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( double,                  Kokkos::LayoutRight, Kokkos::LayoutStride, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( double,                  Kokkos::LayoutStride, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( double,                  Kokkos::LayoutStride, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( double,                  Kokkos::LayoutStride, Kokkos::LayoutStride, Kokkos::HostSpace)
#endif
#if defined (KOKKOSKERNELS_INST_FLOAT)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( float,                  Kokkos::LayoutLeft, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( float,                  Kokkos::LayoutLeft, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( float,                  Kokkos::LayoutLeft, Kokkos::LayoutStride, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( float,                  Kokkos::LayoutRight, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( float,                  Kokkos::LayoutRight, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( float,                  Kokkos::LayoutRight, Kokkos::LayoutStride, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( float,                  Kokkos::LayoutStride, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( float,                  Kokkos::LayoutStride, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( float,                  Kokkos::LayoutStride, Kokkos::LayoutStride, Kokkos::HostSpace)
#endif
#if defined (KOKKOSKERNELS_INST_KOKKOS_COMPLEX_DOUBLE_)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<double>, Kokkos::LayoutLeft, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<double>, Kokkos::LayoutLeft, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<double>, Kokkos::LayoutLeft, Kokkos::LayoutStride, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<double>, Kokkos::LayoutRight, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<double>, Kokkos::LayoutRight, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<double>, Kokkos::LayoutRight, Kokkos::LayoutStride, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<double>, Kokkos::LayoutStride, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<double>, Kokkos::LayoutStride, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<double>, Kokkos::LayoutStride, Kokkos::LayoutStride, Kokkos::HostSpace)
#endif
#if defined (KOKKOSKERNELS_INST_KOKKOS_COMPLEX_FLOAT_)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<float>, Kokkos::LayoutLeft, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<float>, Kokkos::LayoutLeft, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<float>, Kokkos::LayoutLeft, Kokkos::LayoutStride, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<float>, Kokkos::LayoutRight, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<float>, Kokkos::LayoutRight, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<float>, Kokkos::LayoutRight, Kokkos::LayoutStride, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<float>, Kokkos::LayoutStride, Kokkos::LayoutLeft, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<float>, Kokkos::LayoutStride, Kokkos::LayoutRight, Kokkos::HostSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_BLAS( Kokkos::complex<float>, Kokkos::LayoutStride, Kokkos::LayoutStride, Kokkos::HostSpace)
#endif

#endif

// cuBLAS
#ifdef KOKKOSKERNELS_ENABLE_TPL_CUBLAS

#define KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( SCALAR, LAYOUTX, LAYOUTY, MEMSPACE ) \
template<class ExecSpace> \
struct copy_tpl_spec_avail< \
Kokkos::View<const SCALAR*, LAYOUTX, Kokkos::Device<ExecSpace, MEMSPACE>, \
             Kokkos::MemoryTraits<Kokkos::Unmanaged> >, \
Kokkos::View<SCALAR*, LAYOUTY, Kokkos::Device<ExecSpace, MEMSPACE>, \
             Kokkos::MemoryTraits<Kokkos::Unmanaged> >, \
1> { enum : bool { value = true }; };

#if defined (KOKKOSKERNELS_INST_DOUBLE)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( double,                  Kokkos::LayoutLeft, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( double,                  Kokkos::LayoutLeft, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( double,                  Kokkos::LayoutLeft, Kokkos::LayoutStride, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( double,                  Kokkos::LayoutRight, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( double,                  Kokkos::LayoutRight, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( double,                  Kokkos::LayoutRight, Kokkos::LayoutStride, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( double,                  Kokkos::LayoutStride, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( double,                  Kokkos::LayoutStride, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( double,                  Kokkos::LayoutStride, Kokkos::LayoutStride, Kokkos::CudaSpace)
#endif
#if defined (KOKKOSKERNELS_INST_FLOAT)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( float,                  Kokkos::LayoutLeft, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( float,                  Kokkos::LayoutLeft, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( float,                  Kokkos::LayoutLeft, Kokkos::LayoutStride, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( float,                  Kokkos::LayoutRight, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( float,                  Kokkos::LayoutRight, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( float,                  Kokkos::LayoutRight, Kokkos::LayoutStride, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( float,                  Kokkos::LayoutStride, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( float,                  Kokkos::LayoutStride, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( float,                  Kokkos::LayoutStride, Kokkos::LayoutStride, Kokkos::CudaSpace)

#endif
#if defined (KOKKOSKERNELS_INST_KOKKOS_COMPLEX_DOUBLE_)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<double>, Kokkos::LayoutLeft, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<double>, Kokkos::LayoutLeft, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<double>, Kokkos::LayoutLeft, Kokkos::LayoutStride, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<double>, Kokkos::LayoutRight, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<double>, Kokkos::LayoutRight, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<double>, Kokkos::LayoutRight, Kokkos::LayoutStride, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<double>, Kokkos::LayoutStride, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<double>, Kokkos::LayoutStride, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<double>, Kokkos::LayoutStride, Kokkos::LayoutStride, Kokkos::CudaSpace)
#endif
#if defined (KOKKOSKERNELS_INST_KOKKOS_COMPLEX_FLOAT_)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<float>, Kokkos::LayoutLeft, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<float>, Kokkos::LayoutLeft, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<float>, Kokkos::LayoutLeft, Kokkos::LayoutStride, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<float>, Kokkos::LayoutRight, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<float>, Kokkos::LayoutRight, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<float>, Kokkos::LayoutRight, Kokkos::LayoutStride, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<float>, Kokkos::LayoutStride, Kokkos::LayoutLeft, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<float>, Kokkos::LayoutStride, Kokkos::LayoutRight, Kokkos::CudaSpace)
 KOKKOSBLAS1_COPY_TPL_SPEC_AVAIL_CUBLAS( Kokkos::complex<float>, Kokkos::LayoutStride, Kokkos::LayoutStride, Kokkos::CudaSpace)
#endif



#endif


}
}
#endif
