// SPDX-License-Identifier: Apache-2.0
//===-- wasmedge/common/log.h - Logging system ----------------------------===//
//
// Part of the WasmEdge Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the linkage of opentelemetry logging system.
///
//===----------------------------------------------------------------------===//
#pragma once


#include "opentelemetry/sdk/trace/simple_processor.h"
#include "opentelemetry/sdk/trace/tracer_provider.h"
#include "opentelemetry/trace/provider.h"

// Using an exporter that simply dumps span data to stdout.
#include "opentelemetry/exporters/ostream/span_exporter.h"

namespace trace = opentelemetry::trace;
namespace nostd = opentelemetry::nostd;

namespace WasmEdge {
namespace Otlog {

void initTracer();

nostd::shared_ptr<trace::Tracer> get_tracer();


} // namespace Otlog
} // namespace WasmEdge
